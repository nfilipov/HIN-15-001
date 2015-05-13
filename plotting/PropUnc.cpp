float PropUnc (Upsilon a, Upsilon b){
  return sqrt( (a.RatioError()/a.Ratio())*(a.RatioError()/a.Ratio()) + (b.RatioError()/b.Ratio())*(b.RatioError()/b.Ratio()) );
}
