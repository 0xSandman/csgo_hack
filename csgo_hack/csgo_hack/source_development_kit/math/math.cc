#include "../source_development_kit.hh"

void math::sin_cos(float a, float* s, float* c)
{
	*s = sin(a);
	*c = cos(a);
}

void math::angle_vectors(const vec3_t& angles, vec3_t* forward, vec3_t* right, vec3_t* up)
{
	float sr, sp, sy, cr, cp, cy;

	sin_cos(deg_2_rad(angles[YAW]), &sy, &cy);
	sin_cos(deg_2_rad(angles[PITCH]), &sp, &cp);
	sin_cos(deg_2_rad(angles[ROLL]), &sr, &cr);

	if (forward)
	{
		forward->x = cp * cy;
		forward->y = cp * sy;
		forward->z = -sp;
	}

	if (right)
	{
		right->x = (-1 * sr * sp * cy + -1 * cr * -sy);
		right->y = (-1 * sr * sp * sy + -1 * cr * cy);
		right->z = -1 * sr * cp;
	}

	if (up)
	{
		up->x = (cr * sp * cy + -sr * -sy);
		up->y = (cr * sp * sy + -sr * cy);
		up->z = cr * cp;
	}
}

void math::vector_angles(const vec3_t& forward, vec3_t& angles)
{
	if (forward.y == 0.0f && forward.x == 0.0f)
	{
		angles.x = (forward.z > 0.0f) ? 270.0f : 90.0f;
		angles.y = 0.0f;
	}
	else
	{
		angles.x = atan2(-forward.z, forward.Length2D()) * -180 / M_PI;
		angles.y = atan2(forward.y, forward.x) * 180 / M_PI;

		if (angles.y > 90)
			angles.y -= 180;
		else if (angles.y < 90)
			angles.y += 180;
		else if (angles.y == 90)
			angles.y = 0;
	}

	angles.z = 0.0f;
}

vec3_t math::calculate_angle(vec3_t src, vec3_t dst)
{
	vec3_t angles;
	vec3_t delta;
	delta.x = (src.x - dst.x);
	delta.y = (src.y - dst.y);
	delta.z = (src.z - dst.z);

	double hyp = sqrt(delta.x * delta.x + delta.y * delta.y);
	angles.x = (float)(atanf(delta.z / hyp) * 57.295779513082f);
	angles.y = (float)(atanf(delta.y / delta.x) * 57.295779513082f);

	angles.z = 0.0f;
	if (delta.x >= 0.0) { angles.y += 180.0f; }
	return angles;
}

void math::vector_transform(const vec3_t& some, const matrix3x4& matrix, vec3_t& out)
{
	for (auto i = 0; i < 3; i++)
		out[i] = some.Dot((vec3_t&)* matrix[i]) + matrix[i][3];
}

void math::normalize_angles(vec3_t& angle)
{
	while (angle.x > 89.0f)
		angle.x -= 180.f;

	while (angle.x < -89.0f)
		angle.x += 180.f;

	while (angle.y > 180.f)
		angle.y -= 360.f;

	while (angle.y < -180.f)
		angle.y += 360.f;
}

// (c) mcswaggens

void math::fix_movement(vec3_t old_angles, vec3_t current_angles, float* forward_move, float* side_move, float old_forward_move, float old_side_move)
{
	float delta;
	float old_angles_2;
	float current_angles_2;

	if (old_angles.y < 0.f)
		old_angles_2 = 360.0f + old_angles.y;
	else
		old_angles_2 = old_angles.y;

	if (current_angles.y < 0.0f)
		current_angles_2 = 360.0f + current_angles.y;
	else
		current_angles_2 = current_angles.y;

	if (current_angles_2 < old_angles_2)
		delta = abs(current_angles_2 - old_angles_2);
	else
		delta = 360.0f - abs(old_angles_2 - current_angles_2);

	delta = 360.0f - delta;

	*forward_move = cos(deg_2_rad(delta)) * old_forward_move + cos(deg_2_rad(delta + 90.f)) * old_side_move;
	*side_move = sin(deg_2_rad(delta)) * old_forward_move + sin(deg_2_rad(delta + 90.f)) * old_side_move;
}
