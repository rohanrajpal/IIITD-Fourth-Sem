function eigenCalculation(M,i)
    
    [V,D] = eig(M);
    disp(D);
    disp(V);
    out = imag(D(1)) ~= 0;
    disp(out);
    if(out == 0)
        e_vectorplot = figure('Name',['Plot of Eigenvectors Part ' num2str(i)]);
        filename = ['Eigenvector_part_' num2str(i) '.png'];
        plot(V);
        saveas(e_vectorplot,filename);
        disp('reached')
    else
        disp('Complex eigenvalues, can not plot')
    end
end