#include "mathematics.h"

/**
 * Adds a vector to another. The result is saved in the first vector.
 * Returns a pointer to the first vector.
 */
t_vec2	*add_to_vec(t_vec2 *orig, t_vec2 *other)
{
	orig->i += other->i;
	orig->j += other->j;
	return (orig);
}

/**
 * Subtracts a vector from another. The result is saved in the first vector.
 * Returns a pointer to the first vector.
 */
t_vec2	*subt_from_vec(t_vec2 *orig, t_vec2 *other)
{
	orig->i -= other->i;
	orig->j -= other->j;
	return (orig);
}

/**
 * Returns a vector's absolute value.
 */
float	abs_vec(t_vec2 *vec)
{
	return (sqrt(vec->i * vec->i + vec->j * vec->j));
}

/**
 * Normalizes a vector.
 * Returns a pointer to the same vector.
 */
t_vec2	*normalize_vec(t_vec2 *vec)
{
	float	abs;

	abs = abs_vec(vec);
	vec->i /= abs;
	vec->j /= abs;
	return (vec);
}
