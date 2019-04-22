function [conditional_prob,freqmatrix,b_fractionsites_base_s0,b_fractionsites_base_s1] = Q1(S0,S1)
     freqmatrix = zeros(4);

    % X A G C T
    % A
    % G
    % C
    % T
    Seqnames = {'A','G','C','T'};
    SeqNumber = {1,2,3,4};
    mapping = containers.Map(Seqnames,SeqNumber);
%     length(S0)
      for i=1:length(S0)
          freqmatrix( mapping(S1(i)),mapping(S0(i)) ) = freqmatrix( mapping(S1(i)),mapping(S0(i)) ) + 1 ;
      end
%     disp(freqmatrix)

    % S0
    b_fractionsites_base_s0 = [0,0,0,0];
    freqtrans = transpose(freqmatrix);
    for i=1:4
    %     freqtrans(i)
        b_fractionsites_base_s0(i) = sum(freqtrans(i,:))/600;
    end
%     disp(b_fractionsites_base_s0)

    % S1
    b_fractionsites_base_s1 = [0,0,0,0];
    for i=1:4
        b_fractionsites_base_s1(i) = sum(freqmatrix(i,:))/600;
    end
%     disp(b_fractionsites_base_s1)

    % conditional probabilty
    conditional_prob = freqmatrix;
    for i=1:4
        for j =1:4
            conditional_prob(i,j) = conditional_prob(i,j) / sum(freqtrans(j,:));
        end
    end
%     disp(conditional_prob);
end
