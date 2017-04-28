/*
 * main.c
 * 
 * Copyright 2017 Juan G Aguilar <asakura@ubuntu>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include 'funciones.h'




int main(int argc, char **argv)
{
	
	double *U = malloc(POINTS3*USIZE*sizeof(double));
	double *UB = malloc(POINTS3*USIZE*sizeof(double));
	double *Fx = malloc(POINTS3*USIZE*sizeof(double));
	double *Fy = malloc(POINTS3*USIZE*sizeof(double));
	double *Fz = malloc(POINTS3*USIZE*sizeof(double));
	double *Fbx = malloc(POINTS3*USIZE*sizeof(double));
	double *Fby = malloc(POINTS3*USIZE*sizeof(double));
	double *Fbz = malloc(POINTS3*USIZE*sizeof(double));
	double *Fax = malloc(POINTS3*USIZE*sizeof(double));
	double *Fay = malloc(POINTS3*USIZE*sizeof(double));
	double *Faz = malloc(POINTS3*USIZE*sizeof(double));
	double *C = malloc(POINTS3*USIZE*sizeof(double));
	return 0;
	
	
		
}

