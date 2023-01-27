/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:45:29 by tquere            #+#    #+#             */
/*   Updated: 2023/01/27 13:26:24 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

typedef struct s_ray
{
	double cam_x;
	double ray_dir_x;
	double ray_dir_y;

	int		cur_box_x;
	int		cur_box_y;

	double	s_dist_x;
	double	s_dist_y;

	double	d_dist_x;
	double	d_dist_y;

	double	step_x;
	double	step_y;
	double	wall_dist;

	int 	line_height;
	int		bot_pix;
	int		top_pix;

	int		hit;
	int		side;

	int		type_hit;

}	t_ray;


void	raycast(t_cub *cub, t_paint *paint);

#endif
