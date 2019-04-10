function Question1_foreach(M,i)
    % a part, find equilibrium points
    [solx,soly] = findEqPoints(M,i);
    % b and c part, find eigenvalues and corresponding eigenvectors
    % this function plots the eigenvectors as well
    eigenCalculation(M,i);
    % d part, plot the direction fields
    directionFields(M,solx,soly,i);
    % e part, explained in Question1_main
end
    