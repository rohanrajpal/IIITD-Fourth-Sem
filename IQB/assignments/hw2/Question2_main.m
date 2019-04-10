close all
syms x y
F = x * ( 1+ 1.3 * (1-x)) - 0.5 *x*y;
G = 0.3*y + 1.6 * x*y;
%Part a; calculate jacobian
Question2Jacobian();
% Find the direction fields around the euilibrium point
Ques2directionfields();
%{
    The required plots
    Phase plane plot is 
    Steady state plot of P is
    Steady state plot of Q is
    Time series plot is 
    %}
Q2Plots(300);
%{
The dynamics are stable as we can clearly see from
the time series plots that p and q converge over time. 
The oscillations from time series plot are damped.

Last part:

We cannot plot the eigenvector as the eigenvectors come out to be complex
and cannot be plotted on the real plane.
In Question2Jacobian() I have calulated the required eigenvalues and you
can see in the console that they are complex.
%}

