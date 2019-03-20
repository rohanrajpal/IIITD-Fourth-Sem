aVector =zeros(1,100000);
yVector = zeros(1,100000);
for a = 1.4:0.01:4
   %call assignment to give p1 after 100 iterations
    [yafter100,xafter100] = assignment1(a,100,0.6);
   %100 times call assignment1 to give peq for 1 iteration and plot
   hold on
   [currentY,currentX] = assignment1(a,1,xafter100);
   for i=1:100
       [currentY,currentX] = assignment1(a,1,currentX);
       aVector = [aVector,a];
       yVector = [yVector,currentY];
%        plot(a,currentY,'k.');
   end
end
finalPlot = plot(aVector,yVector,'o');
% set(finalPlot,'markersize',0.5)