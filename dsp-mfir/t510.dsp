mfir(N,T) = par(n,N,_) <: par(t,T, par(n,N, @(t):*(1/(1+n+t)))) :> par(n,N,_);

// tous les tests on la même quantité de calculs
t150 = mfir(1,50);
t225 = mfir(2,25);
t510 = mfir(5,10);
t105 = mfir(10,5);


process = t510;
