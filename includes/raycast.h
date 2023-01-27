/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:45:29 by tquere            #+#    #+#             */
/*   Updated: 2023/01/27 18:26:20 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

typedef struct s_ray
{
	float	cam_x;
	float	ray_dir_x;
	float	ray_dir_y;

	int		cur_box_x;
	int		cur_box_y;

	float	s_dist_x;
	float	s_dist_y;

	float	d_dist_x;
	float	d_dist_y;

	float	step_x;
	float	step_y;
	float	wall_dist;

	float	line_height;
	int		bot_pix;
	int		top_pix;

	int		hit;
	int		side;

	int		type_hit;

}	t_ray;

void	raycast(t_cub *cub, t_paint *paint);
void	get_ray(t_cub *cub, int x, t_ray *ray);
void	get_vector(t_cub *cub);

#endif
