/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   2021.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/21 17:36:00 by nsterk        #+#    #+#                 */
/*   Updated: 2020/12/22 18:49:50 by sofferha      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	putPic(char **pic, int x, int y)
{
	int i = 0;
	int x_axis;
	int y_axis;

	if (y < 0)
	{
		while (y < 0)
		{
			printf("\n");
			y++;
		}

	}
	else
		while (y)
		{
			printf("\n");
			y--;
		}
	while (pic[i])
	{
		x_axis = x;
		while (x_axis)
		{
			printf(" ");
			x_axis--;
		}
		printf("%s\n", pic[i]);
		i++;
	}
}

void setColour(colour)
{
	if (colour == 0)
		printf("\e[0;38;5;1m");
	else if (colour == 1)
		printf("\e[0;38;5;162m");
	else if (colour == 2)
		printf("\e[0;38;5;201m");
	else if (colour == 3)
		printf("\e[0;38;5;21m");
	else if (colour == 4)
		printf("\e[0;38;5;14m");
	else if (colour == 5)
		printf("\e[0;38;5;121m");
	else if (colour == 6)
		printf("\e[0;38;5;83m");
	else if (colour == 7)
		printf("\e[0;38;5;227m");
	else if (colour == 8)
		printf("\e[0;38;5;214m");
	else if (colour == 9)
		printf("\e[0;38;5;197m");
}

int		changeColour(int colour)
{
	if (colour < 9)
		colour++;
	else
		colour = 0;
	return (colour);
}

int	main(void)
{
	char	**pic;
	int		x = 20;
	int		y = 20;
	int		timer = 3;
	int		colour = 0;
	                               
	pic[0] = " #####     ####    #####    ###  ";
	pic[1] = "##   ##   ##  ##  ##   ##  ###   ";
	pic[2] = "    ###  ##   ##      ###     #  ";
	pic[3] = "   ###   ##   ##     ###     ##  ";
	pic[4] = "  ##     ##   ##    ##       ##  ";
	pic[5] = " ##      ##  ##    ##        ##  ";
	pic[6] = "#######   ####    #######  ######";
	pic[7] = NULL;
		while (x)
		{
			printf("\e[1;1H\e[2J");
			setColour(colour);
			putPic(pic, x, y);
			usleep(100000);
			if (y > 47)
			{
				y = -y;
				colour = changeColour(colour);
			}
			else if (!y)
				colour = changeColour(colour);
			y--;
			x--;
		}
		while (colour < 10)
		{
			printf("\e[1;1H\e[2J");
			setColour(colour);
			colour++;
			putPic(pic, x, y);
			usleep(500000);
			printf("\e[1;1H\e[2J");
		}
	printf("\e[0m");
	return (0);
}
