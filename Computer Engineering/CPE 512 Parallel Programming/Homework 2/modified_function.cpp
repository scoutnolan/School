void compute_temp() {
    MPI_Status status;
    #define Temp_buf(x,y) temp_buf[(x)*total_cols+y] // *(temp_buf+x*total_cols+y)
    double *temp_buf = new double[total_rows_on_proc*total_cols];

    bool down_flag = true; //flags to check for out of bounds
    bool up_flag = true;

    if(up_pr > numprocs - 1) up_flag = false;//set dlags to false if out of bounds
    if(down_pr < 0) down_flag = false;
    // communication phase using Blocking Receives

    // to be replaced with other communication methods in assignment
    // Begin of communication phase
    for (int i=0;i<num_iterations;i++) {
        if (rank%2==0) { // even numbered processes
            if(up_flag){
                MPI_Send(&temp[active_rows_on_proc*total_cols],total_cols,
                        MPI_DOUBLE,up_pr,123,MPI_COMM_WORLD);
                MPI_Recv(&temp[(active_rows_on_proc+1)*total_cols],
                        total_cols,MPI_DOUBLE,
                        up_pr,MPI_ANY_TAG,MPI_COMM_WORLD,&status);
            }
            if (rank>0) {
                if(down_flag){
                    MPI_Send(&temp[total_cols],total_cols,MPI_DOUBLE,
                            down_pr,123,MPI_COMM_WORLD);
                    MPI_Recv(&temp[0],total_cols,MPI_DOUBLE,down_pr,
                            MPI_ANY_TAG,MPI_COMM_WORLD,&status);
                }
            }
        }
        else { // odd numbered processes
            if(down_flag){
                MPI_Recv(&temp[0],total_cols,MPI_DOUBLE,down_pr,MPI_ANY_TAG,
                        MPI_COMM_WORLD,&status);
                MPI_Send(&temp[total_cols],total_cols,MPI_DOUBLE,
                        down_pr,123,MPI_COMM_WORLD);
            }

            if (rank < numprocs-1) {
                if(up_flag){
                    MPI_Recv(&temp[(active_rows_on_proc+1)*total_cols],
                            total_cols,MPI_DOUBLE,up_pr,
                            MPI_ANY_TAG,MPI_COMM_WORLD,&status);
                    MPI_Send(&temp[active_rows_on_proc*total_cols],
                            total_cols,MPI_DOUBLE,up_pr,
                            123,MPI_COMM_WORLD);
                }
            }
        }
        // End of communication phase

        // local stenciled computation phase 
        for (int j=1;j<=active_rows_on_proc;j++) {
            for (int k=1;k<=total_cols-2;k++) {
                Temp_buf(j,k)=0.25*(Temp(j-1,k)+Temp(j+1,k)+
                        Temp(j,k-1)+Temp(j,k+1));
            }
        }
        for (int j=1;j<=active_rows_on_proc;j++) {
            for (int k=1;k<=total_cols-2;k++) { 
                Temp (j,k)=Temp_buf(j,k);
            }
        }
    }
    delete temp_buf;
}