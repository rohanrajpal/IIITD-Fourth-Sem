function [solx,soly] = findEqPoints(M,i)
    syms x y;
    Eq1 = M(1,1) * x + M(1,2) * y;
    Eq2 = M(2,1) * x + M(2,2) * y;
    
    [solx,soly] = solve( Eq1 == x, Eq2 == y);
%     disp('The Equilibrium point of part',i,'is:');
    disp(['The Equilibrium point of part ' num2str(i) ' is: ']) ;
    disp(solx,soly);
%     figure;
%     plot(solx,soly,'r*')
    grid on;
end