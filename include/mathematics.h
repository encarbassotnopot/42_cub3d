#ifndef MATHEMATICS_H
# define MATHEMATICS_H
# include <math.h>

typedef struct s_vec2
{
	float	i;
	float	j;
}			t_vec2;

t_vec2		*add_to_vec(t_vec2 *orig, t_vec2 *other);
t_vec2		*subt_from_vec(t_vec2 *orig, t_vec2 *other);
float		abs_vec(t_vec2 *vec);
t_vec2		*normalize_vec(t_vec2 *vec);
#endif