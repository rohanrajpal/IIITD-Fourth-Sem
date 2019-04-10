function Ques2directionfields()
    syms altX altY
    altF = altX .* ( 1 + 1.3 .* (1-altX)) - 0.5 .* altX .*altY;
    altG = 0.3 .* altY + 1.6 .* altX .* altY;
    [solx,soly] = solve(altF == altX, altG == altY);
%     steps = 
    x1 = solx(3)-0.05:(1/200):solx(3)+0.05;
    x2 = soly(3)-0.05:(1/200):soly(3)+0.05;
    
    [x,y] = meshgrid(x1,x2);
    F = x .* ( 1+ 1.3 .* (1-x) ) - 0.5 .* x .* y;
    G = 0.3 .* y + 1.6 .* x .* y;
    
    deltaF = F - x;
    deltaG = G - y;
    
    
    disp(solx,soly)
    filename = 'Question 2 Direction Fields.png';
    q2_direction_fields = figure('Name', filename);
    
    quiver(x,y,deltaF,deltaG);
    hold on
    plot(solx(3),soly(3),'r*');
    grid on
    saveas(q2_direction_fields, filename);
end