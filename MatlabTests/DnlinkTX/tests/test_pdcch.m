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

x = repmat([0, 0, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0]', 10, 1);
d = dcch(x(1:27), 65500);
m = pdcch(tx.enb, d, 0);

m = [m; pdcch(tx.enb, d, 4)];
m = [m; pdcch(tx.enb, d, 2)];
m = [m; pdcch(tx.enb, d, 8)];

g = reshape(m, size(m,1)*size(m,2), 1);
gr = zeros(length(g)*2,1);
gr(1:2:end) = real(g)*21213*sqrt(2);
gr(2:2:end) = imag(g)*21213*sqrt(2);

f = fopen('test_pdcch.outfile.ground', 'w');
fprintf(f,'%d,', floor(gr));
fclose(f);
