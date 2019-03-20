%SPIDERWEB:  Draw the spiderweb plot of the forward trajectory of a point.
%   SPIDERWEB(f,x0,N) creates a 'spiderweb diagram' or a 'cobweb plot' for 
%   a given continuous map of the interval [0 1]. 
%
%   This type of graph is used to visualize successive iterations of an 
%   interval map f. Given an initial point x0, the segments that make up 
%   the diagram connect the points 
%        (x0, f(x0)), (f(x0), f(f(x0))), (f(f(x0)), f(f(f(x0)))), ...
%
%   The arguments for SPIDERWEB are the following:
%       o f  - a continuous map of the interval [0 1] into itself. Maps 
%              that do not take the interval [0 1] back into itself may not 
%              produce the correct spideweb plot.
%       o x0 - the initial point. 
%       o N  - the number of iterations. SPIDERWEB computes the forward 
%              trajectory of length N for the point x0. These points are
%              stored in the vector xIm = X-IMAGES, so that
%                      xIm = [ x0 f(x0) ... (f^N)(x0) ]
%
%   Here are some sample function calls. 
%       o For the symmetric tent map, try:
%          >> f = @(x) (2*x).*(x<0.5) + (2-2*x).*(x>=0.5);
%          >> spiderweb(f, 0.124, 50);
%
%       o For the standard quadratic (logistic) map, try:
%          >> f = @(x) (4*x).*(1-x);
%          >> spiderweb(f, 0.12, 50);
%
%   For interesting examples exhibiting periodicity (finite orbits), see
%   http://mathworld.wolfram.com/LogisticMap.html

function xIm = spiderweb(f, x0, N)

% Pre-allocate a vector xIm for the images. By the end, we will have
%            xIm = [x0 f(x0) f( f(x0) ) f( f( f(x0) ) ) ... ]
xIm = [x0 zeros(1,N)];

% Plot the curve for f and the line y = x (for the spiderweb process).
figure(1); clf;
xx = linspace(0,1,500);
plot(xx,xx,'b','LineWidth',2);
axis([0 1 0 1]); box on; hold on;
plot(xx,f(xx),'r','LineWidth',2);
xlabel('x'); ylabel('f(x)'); 
title({['Spiderweb plot of length N = ', num2str(N),' for']; ...
       ['f = ',func2str(f),'     and     x0 = ', num2str(x0)]});

% Main function loop: Suppose we are on the kth iteration. First, we
% compute xIm(k) = (f^k)(x0). Then, draw the vertical line from the point
% ( xIm(k-1), xIm(k-1) ) on the line y = x to the point (xIm(k-1), xIm(k)).
% Next, draw the horizontal line connecting this image point on the curve
% back to the line y = x.

for n = 2:N
    xIm(n) = f(xIm(n-1));
    line([xIm(n-1) xIm(n-1)],[xIm(n-1) xIm(n)],'Color','k','Marker','o');
    line([xIm(n-1) xIm(n)],[xIm(n) xIm(n)],'Color','k','Marker','o');
    drawnow;
end

% Now plot the images projected onto [0 1]
hold on;
plot(xIm, 0*xIm, 'g.');

