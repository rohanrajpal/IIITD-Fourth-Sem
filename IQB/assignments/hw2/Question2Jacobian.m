
function Question2Jacobian()
    syms x y
    F = x * ( 1+ 1.3 * (1-x)) - 0.5 *x*y;
    G = 0.3*y + 1.6 * x*y;
    JacobianMatrix = jacobian( [ F,G] , [x,y]);
    % Calculating eigenvectors and eigenvalues
    
    JacAtEquilibrum = double(subs(JacobianMatrix, [x,y],[0.4375,1.4625]));
    disp((JacAtEquilibrum));
    eigenCalculation(JacAtEquilibrum, 'Jacobian');
    disp(JacobianMatrix);
end