function  fun=MyFun1(x)
f=zeros(1,length(x));
for i=1:length(x)
    if((mod(i,2) == 0))
        f(i/2)=(100*(x(i-1)^2-x(i))^2+(x(i-1)-1)^2);
    end
end
syms sum(f);
fun=sum(f);