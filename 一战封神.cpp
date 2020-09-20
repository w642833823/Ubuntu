float Q_rsqrt( float number ) {
    long i;
    float x2, y;
    const float threehalfs = 1.5F;
  x2 = number * 0.5F;
    y   = number;
    i   = * ( long * ) &y; 
  // evil floating point bit level hacking
    i   = 0x5f3759df - ( i >> 1 ); // what the fuck?
    y   = * ( float * ) &i;
    y   = y * ( threehalfs - ( x2 * y * y ) ); 
// 1st iteration
    // y   = y * ( threehalfs - ( x2 * y * y ) );
 // 2nd iteration, this can be removed
  #ifndef Q3_VM
    #ifdef __linux__
      assert( !isnan(y) );
 // bk010122 - FPE?
    #endif   
 #endif    
return y; }

/*，而且比标准的sqrt()函数快4倍！

这个简洁的定数，最核心，也是最让人费解的，就是标注了what the fuck的一句 i   = 0x5f3759df - ( i >> 1 )；再加上y   = y * ( threehalfs - ( x2 * y * y ) )。


两句话就完成了开方运算！而且注意到，核心那句是移位运算，速度极快！特别在很多没有乘法指令的RISC结构CPU上，这样做是极其高效的*/