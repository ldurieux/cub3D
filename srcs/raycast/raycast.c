/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:45:31 by tquere            #+#    #+#             */
/*   Updated: 2023/01/28 10:44:00 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "raycast.h"

static void	cast_ray(t_cub *cub, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->s_dist_x < ray->s_dist_y)
		{
			ray->s_dist_x += ray->d_dist_x;
			ray->cur_box_x += ray->step_x;
			ray->side = EAST;
			if (ray->ray_dir_x > 0)
				ray->side = WEST ;
		}
		else
		{
			ray->s_dist_y += ray->d_dist_y;
			ray->cur_box_y += ray->step_y;
			ray->side = SOUTH;
			if (ray->ray_dir_y > 0)
				ray->side = NORTH ;
		}
		if (cub->map.data[ray->cur_box_y * cub->map.width + ray->cur_box_x] > 1)
			ray->hit = 1;
	}
	ray->type_hit = cub->map.data[ray->cur_box_y
		* cub->map.width + ray->cur_box_x];
}

static void	get_distance(t_ray *ray)
{
	if (ray->side == EAST || ray->side == WEST)
		ray->wall_dist = (ray->s_dist_x - ray->d_dist_x);
	else if (ray->side == NORTH || ray->side == SOUTH)
		ray->wall_dist = (ray->s_dist_y - ray->d_dist_y);
}

static void	get_height(t_ray *ray)
{
	ray->line_height = (int)(WIN_HEIGHT / ray->wall_dist);
	ray->bot_pix = -ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->bot_pix < 0)
		ray->bot_pix = 0;
	ray->top_pix = ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->top_pix >= WIN_HEIGHT)
		ray->top_pix = WIN_HEIGHT - 1;
}

static float	get_hit_point(t_cub *cub, t_ray *ray)
{
	float	wall_x;

	wall_x = 0;
	if (ray->side == EAST || ray->side == WEST)
		wall_x = (cub->player.y + ray->wall_dist * ray->ray_dir_y);
	else if (ray->side == SOUTH || ray->side == NORTH)
		wall_x = (cub->player.x + ray->wall_dist * ray->ray_dir_x);
	wall_x -= floor((wall_x));
	return (wall_x);
}

void	raycast(t_cub *cub, t_paint *paint)
{
	t_ray	ray;
	t_wall	wall;
	int		x;

	get_vector(cub);
	x = 0;
	while (x < WIN_WIDTH)
	{
		get_ray(cub, x, &ray);
		cast_ray(cub, &ray);
		get_distance(&ray);
		get_height(&ray);
		wall.face_x = get_hit_point(cub, &ray);
		wall.face_idx = ray.side;
		wall.draw_x = x;
		wall.height = ray.line_height / WIN_HEIGHT;
		cub_draw_wall(&cub->map, paint, wall);
		x++;
	}
}
