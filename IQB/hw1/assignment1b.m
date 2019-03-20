clc;clear;
assignment1bd(1.5,1000,0.4);
figure;
assignment1bd(2.5,1000,0.5);
figure;
assignment1bd(3.5,1000,0.6);
function[finaly,finalx] = assignment1bd(givenA,iterations,yInitial)
    % givenA = 2.5;
%     hold off;
    xVector = [0];
    yVector = [yInitial];
    for i = 2:iterations
         ansi = theYFunction(yVector(i-1),givenA)
         yVector = [yVector,ansi ];
         xVector = [xVector, i-1];
    end
    plot(xVector,yVector);
    function [ansi] = theYFunction(in1,a)
        ansi = a.*in1.*(1-in1);
    end
end