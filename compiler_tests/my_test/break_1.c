int f(){
    int i = 0;
    for (i = 0; i < 5; i++ ){
        if(i > 3){
            return i;
            break;
        }
    }
    return 9;
}