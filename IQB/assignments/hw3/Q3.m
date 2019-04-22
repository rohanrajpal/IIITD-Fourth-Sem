% I took the given genomic sequences and constructed a matrix from them
% the matrix satiesfies the given conditions( diagnol values are the largest
% and all values are positive)
% 
% (a)
% I ran the code over 10000 iterations over the vector intially p0
% It tends towards a value close to the eigenvector of
% M with eigenvalue 1.
% 
% (b)
% Using a computer we get the following eigenvalues
%     1.0000
%     0.5712
%     0.1608
%     0.2133
% Is 1 an eigenvalue?   
% 
% Yes 1 is an eigen value 
% 
% Is your estimate of the equilibrium close to its eigenvector?
% The vector I get in part a
% is close to the eigenvector with a RMSE (Root mean sqaure error)
% of 2.5134e-16
% 
% (c)
% Theorem 1.
% 
% A Markov matrix always has ?1 = 1 as its largest eigenvalue and
% has all eigenvalues satisfying |?| ? 1.The eigenvector corresponding to ?1
% has all nonnegative entries
% 
% We can clearly see that among all eigenvalues, 1 is the largest eigenvalue
% The eigenvector corresponding to it is:
%     0.2753
%     0.2774
%     0.2303
%     0.2169
% Theorem 2. A Markov matrix, all of whose entries are positive (i.e., nonzero),
% always has 1 as a strictly dominant eigenvalue.There will be only one eigenvector (up to scalar multiplication) associated with ? = 1
% 
% This is also true, as 
% taking the following markov matrix
%     0.4901    0.3333    0.1006    0.1141
%     0.3179    0.4752    0.1384    0.1208
%     0.1060    0.0922    0.4969    0.2819
%     0.0861    0.0993    0.2642    0.4832
% This has the following eigenvalues
%     1.0000
%     0.5712
%     0.1608
%     0.2133
% 1 is the strictly dominant eigenvalue    
% There is only one eigenvalue 1 and only one eigenvector(normalised printed below) corresponding to it.
% 
%     0.2753
%     0.2774
%     0.2303
%     0.2169
clc;clear;

S0 = ['CGGCCTGAAGCGACGTCGTATCATATCAATCGCATGTCATCGCCGTCTACGCCCCGGAGACTAAACCCTGCCGCATGATAATGTGGTCTACTGAGTTCTTCATGG' ...
    'GGCAGGGGATCATGAATCGTGCAAGACCCAAGCCCCTACCAAAGAGACCACGAGGTCATTAGTCTTCCTAGGCGACTAGTTCTGTCGCGCTCTCACCATTTCTTC' ...
    'TCATGGGGAACTCAGAACTGGATGAATGTCCCTTAGACCCTGTTTTCCTCGCGTGAAAAAGTACCTTTTAGAGCATTCAAATATGTCGACCGAAGAACCTGTAGT' ...
    'TAAATCCGTCGCATTAACTCTTAGAGGGCCGGAGCTAAGACCAAGTCTATCACGCGCGCTCAAACATGAGGGAGATTGGTCCATTTGTGGGAGATTAGCCAAGC' ...
    'ATCATGGAACTACCTCTTTCCATACAATTTCGGCCTTGCCATATTCCATTTAATGAAAGCTACGCCTCGAGCCGTTAAGCCCGTCAATAGAACTGGTTACCTAAGG' ...
    'CCAGTACCAACGGAATGGCTGGAGGTCGCGCCACGAATATGGTGCCTTTTTCCTGTAGCTCGTGTCGGCCGAAGA'];

S1 = ['AGGCGTCAAGTGTCGGCGGGGCATATTAATGGCGTGTTGCTAAGCTGGACAGTCAAAGTGCCCAACTCAGCTGCGCCGCAGCGTATTCCGACGGCTTCTCCATG' ...
 'AGGGAAAAGATCGCAAAACGGGTAAGTTTTAAATTTGTAATAATAAGACGATTTGCCAACTGGTCCCGAAAGGGGAATGAGTTTGCCACAGACCCCCTGTCTGT' ...
 'TCGTCCCAAAAATCAGGGTCCAGATGAGTTGTACCTGAGGGTCCATTTCTTCTTTTAGCTGATTGATTCCCGGATGACCCCTACGTGTCGCTCAGAAAGACAGTA' ...
 'CGTCGACGCGTCACCTTAACATAGGGGTTGCCCAGGCCCGGCCCTAACCGAATTGGCATCCACAAACATAGGAAAGATTGATCCAATAAAAAGAAATCAGCCGC' ...
 'GTACCATTATGTTAGCTATATCTGGGCATTGGCGTCCGTGCCGTCCTTTGACTAATAACGGTTACTCCCCAAGCAGTTATACCGGTGGGCAAAACTGGTCGATGG' ...
 'ACTCGGCGGTGAATAGTCCGATCGGCGCACACGCCATGAGCAGGATGCATTCTTCCTGTAACCTGTGACAACTGCGGG'];
M = Q1(S0,S1);

%This is the matrix that I have made, all of its entries
% are positive and diagnol values 
% R = [ 90,3,3,2;3,79,8,2;2,4,96,5;5,1,3,94];
% conditional_prob = R;
% freqtrans = transpose(R);
% for i=1:4
%     for j =1:4
%         conditional_prob(i,j) = conditional_prob(i,j) / sum(freqtrans(j,:));
%     end
% end
% M = conditional_prob;
% alpha = 0.5;
% M = [ 1-alpha, alpha/3, alpha/3, alpha/3; ...
%     alpha/3, 1-alpha, alpha/3, alpha/3; ...
%     alpha/3, alpha/3, 1-alpha, alpha/3; ...
%     alpha/3, alpha/3, alpha/3, 1-alpha ] ; 
disp('The markov matrix');
disp(M);
p0 = [0.2;0.3;0.25;0.25];

[V,D] = eig(M);
disp('The eigenvectors are');
% disp(V);
% for i =1:4
%     V(:,i) =  V(:,i) ./ sum(V(:,i));
% end
disp(V);
disp('And the respective eigenvalues are');
disp(D);
prev = p0;

for i=1:10000
    next = M * prev;
    prev = next;
end
disp('The equilibrium vector after 10000 iterations');
disp(next)

disp('It is valid, the sum of columns is printed below');
disp(sum(next))

V1 = next;
% V2 = V(:,1);

eigenvectorpos = -1;

for i=1:4
%     disp(['Di is ', num2str(D(i,i))]);
    if single(D(i,i)) == 1.0000
        eigenvectorpos = i;
%         disp(['broke at ',num2str(i)]);
        break;
    end
end

V2 = V(:,eigenvectorpos) ./ sum(V(:,eigenvectorpos));

disp('The eigenvector (normalized) is');
disp(V2);

meanval = mean((V1-V2).^2);
RMSE = sqrt(meanval);
disp('The error between vectors is');
disp(RMSE);

