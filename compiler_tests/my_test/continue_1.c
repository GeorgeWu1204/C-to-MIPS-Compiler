
int f(){
    int i = 0;
    int g = 0;
    for (i = 0; i < 5; i++ ){
       
        if(i > 3){
            continue;
        }
        g++;
    }
    return g;
}