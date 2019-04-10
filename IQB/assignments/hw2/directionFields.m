function directionFields(M,solx,soly,i)
    
    [X,Y]=meshgrid(-2:.5:2,-2:.5:2);
    diffM = M - [1,0 ; 0,1 ] ;

    deltax = diffM(1,1) * X + diffM(1,2) * Y;
    deltay = diffM(2,1) * X + diffM(2,2) * Y;
    
    Q1dirfields_fig = figure('Name',['Plot of directionfields Part ' num2str(i)]);
    quiver(X,Y,deltax,deltay)
    hold on
    plot(solx,soly,'r*')
    grid on
    saveas(Q1dirfields_fig,['Plot of directionfields Part ' num2str(i) '.png']);
end