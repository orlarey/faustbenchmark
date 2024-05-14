ex1 = @(1);
ex2 = _ <: par(i, 10, @(i)*(i/100+0.1)) :> _; // un simple fir
ex3 = _ <: par(i, 20, @(i)*(i/100+0.1)) :> _; // un simple fir

process = ex3;