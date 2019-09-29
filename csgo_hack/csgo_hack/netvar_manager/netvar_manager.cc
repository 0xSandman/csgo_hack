#include "../source_development_kit/source_development_kit.hh"

netvar_manager::netvar_manager()
{
	for (auto client_class = interfaces::client->get_classes(); client_class; client_class = client_class->next)
		if (client_class->recv_table)
			dump_recursive(client_class->recv_table);
}

void netvar_manager::dump_recursive(valve::recv_table* table)
{
	for (auto i = 0; i < table->num_props; ++i)
	{
		auto property = &table->props[i];

		if (!property || isdigit(property->var_name[0]))
			continue;

		if (strcmp(property->var_name, "baseclass") == 0)
			continue;

		if (property->recv_type == 6 && property->data_table != nullptr && property->data_table->net_table_name[0] == 'D')
			dump_recursive(property->data_table);

		std::string string_hash = table->net_table_name;
		string_hash += "->";
		string_hash += property->var_name;

		map_offsets[fnv_hash(string_hash.c_str())] = property;
	}
}