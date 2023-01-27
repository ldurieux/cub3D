/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:45:31 by tquere            #+#    #+#             */
/*   Updated: 2023/01/27 16:45:31 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "raycast.h"

//-------------Remove------------
#include <stdio.h>

void get_ray(t_cub *cub, int x, t_ray *ray)
{

	//Calcul la direction du ray a cast
	ray->cam_x = 2 * x / (double)WIN_WIDTH - 1;
	ray->ray_dir_x = cub->player.dir_x + cub->player.pla_x * ray->cam_x ;
	ray->ray_dir_y = cub->player.dir_y + cub->player.pla_y * ray->cam_x ;

	// printf("x:%d, ray_dir_x:%f, ray_dir_y:%f\n",x, ray->ray_dir_x , ray->ray_dir_y);
	// printf("x:%d, pla_x:%f    , pla_y:%f\n",x, cub->player.pla_x , cub->player.pla_y);

	//Calcul dans quel case one est
	ray->cur_box_x = (int)cub->player.x;
	ray->cur_box_y = (int)cub->player.y;

	//Calcul les distance sur x et y
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

	//Calcul les step
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
	//No hit at start
	ray->hit = 0;

	//Unset
	ray->wall_dist = -1;
	ray->side = -1;
}

void	cast_ray(t_cub *cub, t_ray *ray)
{
	//Tant qu'on a pas de hit on avance
	while (ray->hit == 0)
	{
		//On regarde si le plus proche ligne horiton ou vertical
		if (ray->s_dist_x < ray->s_dist_y)
		{	
			//on avance
			ray->s_dist_x += ray->d_dist_x;
			ray->cur_box_x += ray->step_x;
			//Side horitontale
			ray->side = 0;
		}
		else
		{	
			ray->s_dist_y += ray->d_dist_y;
			ray->cur_box_y += ray->step_y;
			ray->side = 1;
		}
		//Check if ray has hit a wall
		if (cub->map.data[ray->cur_box_y * cub->map.width + ray->cur_box_x] > 1)
			ray->hit = 1;
	} 
	ray->type_hit = cub->map.data[ray->cur_box_y * cub->map.width + ray->cur_box_x];
}

void	get_distance(t_ray *ray)
{	
	//Calcul de la distance projetee sur le plan de la cam 
	if(ray->side == 0)
		ray->wall_dist = (ray->s_dist_x - ray->d_dist_x) ;
    else
		ray->wall_dist = (ray->s_dist_y - ray->d_dist_y) ;
}

void	get_height(t_ray *ray)
{	
 	//Calcul de hauteur
    ray->line_height = (int)(WIN_HEIGHT / ray->wall_dist);

	//Pixel bas
	ray->bot_pix = -ray->line_height / 2 + WIN_HEIGHT / 2;
	if(ray->bot_pix < 0)
		ray->bot_pix = 0;

	//Pixel haut
	ray->top_pix = ray->line_height / 2 + WIN_HEIGHT / 2;
    if(ray->top_pix >= WIN_HEIGHT)
		ray->top_pix = WIN_HEIGHT - 1;
}

void	draw_wall(t_ray *ray, t_paint *paint, int x)
{	
	int	color;

	if (ray->type_hit == WALL)
		color = Llx_Green;
	else
		color = Llx_Red;

	//Change brightness
	if (ray->side == 0) 
		color = color / 1;
	if (ray->side == 1) 
		color = color / 2;
	if (ray->side == 2) 
		color = color / 3;
	if (ray->side == 3) 
		color = color / 4;

	//Dessine la ligne de pixel
	int y;

	y = ray->bot_pix;
	while (y < ray->top_pix)
	{
		paint->data[y * paint->width + x] = color;
		y++;
	}
}

void	raycast(t_cub *cub, t_paint *paint)
{
	t_ray	ray;

	cub->player.pla_x = 0;
	cub->player.pla_y = tan(FOV / 2);
	
	cub->player.dir_x = cos(cub->player.dir);
	cub->player.dir_y = -sin(cub->player.dir);
	
	double	old_pla_x;

	old_pla_x = cub->player.pla_x;
    cub->player.pla_x = cub->player.pla_x * cos(cub->player.dir) - cub->player.pla_y * -sin(cub->player.dir);
    cub->player.pla_y = old_pla_x * -sin(cub->player.dir) + cub->player.pla_y * cos(cub->player.dir);

	int 	x;

	x = 0;
	while (x < WIN_WIDTH)
	{	
		get_ray(cub, x, &ray);
		cast_ray(cub, &ray);
		get_distance(&ray);
		get_height(&ray);
		// cub_draw_wall(t_map *map, t_paint *paint, int face, t_vec2 pos_height)
		draw_wall(&ray, paint, x);
		x++;
	}
}
