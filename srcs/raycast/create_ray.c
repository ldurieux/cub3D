/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:12:57 by tquere            #+#    #+#             */
/*   Updated: 2023/01/27 18:20:48 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "raycast.h"

static void	get_step(t_cub *cub, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->s_dist_x = (cub->player.x - ray->cur_box_x) * ray->d_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->s_dist_x = (ray->cur_box_x + 1.0 - cub->player.x) * ray->d_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->s_dist_y = (cub->player.y - ray->cur_box_y) * ray->d_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->s_dist_y = (ray->cur_box_y + 1.0 - cub->player.y) * ray->d_dist_y;
	}
}

static void	get_dist_axis(t_ray *ray)
{
	if (ray->ray_dir_x == 0)
		ray->d_dist_x = 1e30;
	else
		ray->d_dist_x = 1 / ray->ray_dir_x ;
	if (ray->d_dist_x < 0)
		ray->d_dist_x *= -1;
	if (ray->ray_dir_y == 0)
		ray->d_dist_y = 1e30;
	else
		ray->d_dist_y = 1 / ray->ray_dir_y ;
	if (ray->d_dist_y < 0)
		ray->d_dist_y *= -1;
}

void	get_vector(t_cub *cub)
{
	float	old_pla_x;

	cub->player.pla_x = 0;
	cub->player.pla_y = tan(FOV / 2);
	cub->player.dir_x = cos(cub->player.dir);
	cub->player.dir_y = -sin(cub->player.dir);
	old_pla_x = cub->player.pla_x;
	cub->player.pla_x = cub->player.pla_x * cos(cub->player.dir)
		- cub->player.pla_y * -sin(cub->player.dir);
	cub->player.pla_y = old_pla_x * -sin(cub->player.dir)
		+ cub->player.pla_y * cos(cub->player.dir);
}

void	get_ray(t_cub *cub, int x, t_ray *ray)
{
	ray->cam_x = 2 * x / (float)WIN_WIDTH - 1;
	ray->ray_dir_x = cub->player.dir_x + cub->player.pla_x * ray->cam_x ;
	ray->ray_dir_y = cub->player.dir_y + cub->player.pla_y * ray->cam_x ;
	ray->cur_box_x = (int)cub->player.x;
	ray->cur_box_y = (int)cub->player.y;
	get_dist_axis(ray);
	get_step(cub, ray);
	ray->hit = 0;
}
