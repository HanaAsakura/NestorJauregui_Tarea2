/*
 * funciones.c
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
#include 'funciones.h'
double calc_e(double *grid, int i, int j, int k){
	return (1.0/pow(grid[tensor(i,j,k,0)],2.0))*(grid[tensor(i,j,k,0)]*grid[tensor(i,j,k,4)]-0.5*(pow(grid[tensor(i,j,k,1)],2.0)+pow(grid[tensor(i,j,k,2)],2.0)+pow(grid[tensor(i,j,k,3)],2.0)));
}

void calc_Fx(double *U, double *F){
	
	int i,j,k,l;
	
	for(i=0;i<POINTS;i++){
		
		for(j=0;j<POINTS;j++){
			
			for(k=0;k<POINTS;k++){
			
				F[tensor(i,j,k,0)] = U[tensor(i,j,k,1)];
				F[tensor(i,j,k,1)] = (pow(U[tensor(i,j,k,1)],2.0)/U[tensor(i,j,k,0)])+U[tensor(i,j,k,0)]*calc_e(U,i,j,k)*(GAMMA+1.0);
				F[tensor(i,j,k,2)] = U[tensor(i,j,k,1)]*U[tensor(i,j,k,2)]/U[tensor(i,j,k,0)];
				F[tensor(i,j,k,3)] = U[tensor(i,j,k,1)]*U[tensor(i,j,k,3)]/U[tensor(i,j,k,0)];
				F[tensor(i,j,k,4)] = U[tensor(i,j,k,1)]*((U[tensor(i,j,k,4)]/U[tensor(i,j,k,0)])+calc_e(U,i,j,k)*(GAMMA+1.0));
			
			}
		}
	}
}

void calc_Fy(double *U, double *F){
	
	int i,j,k,l;
	
	for(i=0;i<POINTS;i++){
		
		for(j=0;j<POINTS;j++){
			
			for(k=0;k<POINTS;k++){
			
				F[tensor(i,j,k,0)] = U[tensor(i,j,k,2)];
				F[tensor(i,j,k,1)] = U[tensor(i,j,k,1)]*U[tensor(i,j,k,2)]/U[tensor(i,j,k,0)];
				F[tensor(i,j,k,2)] = (pow(U[tensor(i,j,k,2)],2.0)/U[tensor(i,j,k,0)])+U[tensor(i,j,k,0)]*calc_e(U,i,j,k)*(GAMMA+1.0);
				F[tensor(i,j,k,3)] = U[tensor(i,j,k,2)]*U[tensor(i,j,k,3)]/U[tensor(i,j,k,0)];
				F[tensor(i,j,k,4)] = U[tensor(i,j,k,2]*((U[tensor(i,j,k,4)]/U[tensor(i,j,k,0)])+calc_e(U,i,j,k)*(GAMMA+1.0));
			
			}
		}
	}
}

void init(double *U, double *UB, double *Fx, double *Fy, double *Fz, double *Fb, double *Fa){
	
	int i,j,k,l;
	
	for	(i=0; i<POINTS;i++){
	
		for (j=0; j<POINTS; j++){
		
			for (k=0; k<POINTS; k++){
				
				U[tensor(i,j,k,0)]=1.0;
				U[tensor(i,j,k,1)]=0.0;
				U[tensor(i,j,k,2)]=0.0;
				U[tensor(i,j,k,3)]=0.0;
				U[tensor(i,j,k,4)]=25E4;
			
			}
		
		}
	
	}
	
	U[tensor(64,64,64,4)]=10E10;
	
	for	(j=0; j<USIZE;j++){
	
		for (k=0; k<USIZE; k++){
		
			for (l=0; l<USIZE; l++){
			
				UB[tensor(0,j,k,l)]=0.0;
				U[tensor(127,j,k,l)]=0.0;
							
			}
		
		}
	
	}
	
	

}
