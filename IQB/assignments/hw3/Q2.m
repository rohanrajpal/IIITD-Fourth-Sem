clc;clear;
% References
% I've used the following link from the book for the distance code
% http://www.cambridge.org/us/catalogue/catalogue.asp?isbn=9780521525862&resISBN13=9780521525862&parent=1777&ss=res#resource
% And as we can see from the distances
% The jukes cantor distance 0.86613
% The kimura distance 0.97824
% The paralinear distance 0.98257
% 
%     0.4901    0.3333    0.1006    0.1141
%     0.3179    0.4752    0.1384    0.1208
%     0.1060    0.0922    0.4969    0.2819
%     0.0861    0.0993    0.2642    0.4832
% 
% The paralinear distance is the best estimate.
% 
% The paralinear distance does not take any assumptions on the
% type of the Markov matrix and is the most general model to
% calculate the phylogenetic distances.
% The paralinear distance accounts for more hidden mutations
% than jukes cantor or kimura 2 param and gives the most accurate estimate among
% the three.
% format long;
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
     
[F,b,c,d] = Q1(S0,S1);

digitsold = digits(10);

%calculating jukes cantor
A=F-diag(diag(F));
p=vpa(sum(sum(A))/sum(sum(F)));
jukes_cantor_dist = vpa((-3/4)*log(1-4*p/3));
% disp(['The jukes cantor distance ',num2str(double(jukes_cantor_dist))]);
fprintf('(a) The jukes cantor distance %.10f \n',jukes_cantor_dist);
% jukes_cantor_dist = seqpdist({S0, S1},'Method','Jukes-Cantor','Alphabet','NT')
% paralinear_dist = seqpdist({S0, S1},'Method','alignment-score','Alphabet','NT')
% kimura2p_dist = seqpdist({S0, S1},'Method','kimura','Alphabet','NT')

% calculating kimura 2 param distance
N=sum(sum(F));
p1=vpa((F(1,2)+F(2,1)+F(3,4)+F(4,3))/N);
p2= vpa(sum(sum(F(1:2,3:4)+F(3:4,1:2)))/N);
kimura2param_dist =vpa((-1/2)*log(1-2*p1-p2)-(1/4)*log(1-2*p2));
% disp(['The kimura distance ', num2str(double(kimura2param_dist))]);
fprintf('(b) The kimura distance %.10f \n',kimura2param_dist);


%calculating paralinear distance
f1=sum(F);
f2=sum(F');
paralineardist=vpa((-1/4)*(log(det(F))-(1/2)*log( prod(f1)*prod(f2) ) ));
% disp(['The paralinear distance ', num2str(double(paralineardist))]);
fprintf('(c) The paralinear distance %.10f \n',paralineardist);

digits(digitsold);