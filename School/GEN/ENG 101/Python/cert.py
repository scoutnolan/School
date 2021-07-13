#Enter a list of people that have not been certified to use a laboratory

uncert_users=["Dave", "Anna", "Sam", "Jill", "May"]
cert_users=[]   #Empty list because no one has been certified yet

while uncert_users:
    current_user = uncert_users.pop()
    print('Certifying user: ' + current_user)
    cert_users.append(current_user)
    print(cert_users)
print('\nThe following are certified users: ')

for cert_user in cert_users:
    print(cert_user)
