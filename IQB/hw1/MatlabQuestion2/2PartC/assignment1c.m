aVector =zeros(1,100000);
yVector = zeros(1,100000);
r=1;
for a = 1.4:0.01:4
   %call assignment to give p1 after 100 iterations
    [yafter100,xafter100] = assignment1(a,100,0.6);
   %100 times call assignment1 to give peq for 1 iteration and plot
   hold on
   [currentY,currentX] = assignment1(a,1,xafter100);
   for i=1:1000
       [currentY,currentX] = assignment1(a,1,currentX);
       aVector(r) = a;
       
       yVector(r) = currentY;
       r=r+1;
%        plot(a,currentY,'k.');
   end
end
aVector;
finalPlot = plot(aVector,yVector,'k.');
set(finalPlot,'markersize',0.5)