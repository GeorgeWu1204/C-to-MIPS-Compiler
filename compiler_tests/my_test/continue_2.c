int f(){
    int i = 0;
    int g = 0;
    
    while(i < 5){
        if (i < 2){
            i++;
            continue;
        }
        g++;
        i++;
    }
    return g;
}