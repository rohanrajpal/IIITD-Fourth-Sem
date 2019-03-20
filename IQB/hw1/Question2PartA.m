makeAndPlot(1.5,100,0.5)
figure;
makeAndPlot(1.5,100,0.2)
figure;
makeAndPlot(2.5,100,0.5)
figure;
makeAndPlot(2.5,100,0.8)
figure;
makeAndPlot(3.5,100,0.5)
figure;
makeAndPlot(3.5,100,0.8)
function[finaly,finalx] = makeAndPlot(givenA,iterations,xInitial)
%     hold off;
    x = linspace(0,1);
    y = x;
    y2 = theYFunction(x,givenA);
    plot(x,y);
    hold on;
    plot(x,y2);
    x1 = xInitial;
    y1 = theYFunction(x1,givenA);
    
    for i = 1:iterations
        %going from cure to y=x
        x3 = y1;
        y3 = y1;
        line([x1,x3], [y1,y3]);
        %going from y=x to curve
        y1 = theYFunction(x3,givenA);
        x1 = x3;
        line([x1,x3], [y1,y3]);
    end
    finaly = y1;
    finalx = x1;
    function [ansi] = theYFunction(in1,a)
        ansi = a.*in1.*(1-in1);
    end
end
%line([1, 3],[2, 4]);