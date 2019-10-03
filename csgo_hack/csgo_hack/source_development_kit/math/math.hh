namespace math
{
	void sin_cos(float a, float* s, float* c);
	void angle_vectors(const vec3_t& angles, vec3_t* forward, vec3_t* right, vec3_t* up);
	void vector_angles(const vec3_t& forward, vec3_t& angles);
	vec3_t calculate_angle(vec3_t src, vec3_t dst);
	void vector_transform(const vec3_t& some, const matrix3x4& matrix, vec3_t& out);
	void normalize_angles(vec3_t& angle);
	void fix_movement(vec3_t old_angles, vec3_t current_angles, float* forward_move, float* side_move, float old_forward_move, float old_side_move);
}