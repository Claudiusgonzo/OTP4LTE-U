%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% MIT License
%
% Copyright (c) 2016 Microsoft
%
% Permission is hereby granted, free of charge, to any person obtaining a copy
% of this software and associated documentation files (the "Software"), to deal
% in the Software without restriction, including without limitation the rights
% to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
% copies of the Software, and to permit persons to whom the Software is
% furnished to do so, subject to the following conditions:
%
% The above copyright notice and this permission notice shall be included in
% all copies or substantial portions of the Software.
%
% THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
% IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
% FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
% AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
% LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
% OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
% THE SOFTWARE.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

addpath ..

frame = 0;
subframe = 0;

tx.enb = struct('CellRefP',1,'NDLRB',50,'NCellID',11,'NFrame',frame,...
                'NSubframe',subframe,'Ng',1,'PHICHDuration','Normal','CFI',3);

% PHICH
group = 1;
seq = 0;
ack = 1;
g = phich(tx.enb, group, seq, ack);
gi = phichi(tx.enb);

a = zeros(600,1);
a(gi) = g;

gr = zeros(length(a)*2,1);
gr(1:2:end) = real(a)*21213*sqrt(2);
gr(2:2:end) = imag(a)*21213*sqrt(2);

f = fopen('test_phich.outfile.ground', 'w');
fprintf(f,'%d,', floor(gr));
fclose(f);

