file1 = open("temp.txt", "w+")

for i in range(850, 1699):
    a = "<section class=\"column\">\n"
    b = "<a href=\"June2021/1-0"+str(i)+".jpg\"><img src=\"June2021/1-0"+str(i)+".jpg\" style=\"width: 85%\"></a>\n"
    if i >= 1000:
            b = "<a href=\"June2021/1-"+str(i)+".jpg\"><img src=\"June2021/1-"+str(i)+".jpg\" style=\"width: 85%\"></a>\n"

    # if i < 10:
    #     b = "<a href=\"June2021/1-00"+str(i)+".jpg\"><img src=\"June2021/1-00"+str(i)+".jpg\" style=\"width: 85%\"></a>\n"
    # elif i >= 10 | i < 100:
    #     b = "<a href=\"June2021/1-0"+str(i)+".jpg\"><img src=\"June2021/1-0"+str(i)+".jpg\" style=\"width: 85%\"></a>\n"
    # elif i >= 100: 
    #     b = "<a href=\"June2021/1-"+str(i)+".jpg\"><img src=\"June2021/1-"+str(i)+".jpg\" style=\"width: 85%\"></a>\n"
    c = "</section>\n"
    file1.write(a)
    file1.write(b)
    file1.write(c)