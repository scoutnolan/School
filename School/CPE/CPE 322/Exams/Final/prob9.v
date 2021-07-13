module prob9 (input d[3:0], output q[1:0], r[2:0])
{
    parameter divisor = 5;
    reg [divisor:0] temp;
    reg [divisor-1 : 1] temp2;
    // Using d for dividend, q for qoutient, and r for remainder.
    always @(d) begin
        for(i = 0; i < divisor; i = i + 1)begin
            q = {q[divsor - 2 : 0], r[divisor - 1]}
            q2[divisor - 1: 1] = r[divisor-2:0]
            q = q - r;
            if(q[divisor-1] == 1)    begin
                q[0] = 0;
                q = q + r;   end
            else
                q[0] = 1;
        end
    end
}


