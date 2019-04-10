clear; close all;clc;
M = [ 3, 0 ; 1,2];
%{
    Part e
    Stability:
    The equilibrium for this is unstable as the arrows are moving
    away from it
%}
Question1_foreach(M,1);

M = [ 1, -1; 2,4 ];
%{
    Part e
    Stability:
    The equilibrium is unstable as all the arrows arent moving towards
    the equilibrium points, they move in a straight line
%}
Question1_foreach(M,2);

M = [ 1, 2; -1,1 ];
%{
    Part e
    Stability:
    The equilibrium is unstable as all the arrows arent moving towards
    the equilibrium points, they move in a straight line
%}
Question1_foreach(M,3);