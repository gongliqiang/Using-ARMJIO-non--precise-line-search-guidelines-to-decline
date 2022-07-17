function fun=grad(x)
G=zeros(length(x),1);
for i=1:length(x)
    if((mod(i,2) == 0))
        G(i-1,1)=(-400 * x(i-1) * x(i) + 400 * x(i-1)^3 + 2 * x(i-1) - 2);
        b=G(i-1,1)
        G(i,1)=( 200 * x(i) - 200 * x(i-1)^2);
    end
end
fun=G;%∑µªÿÃ›∂»æÿ’Û