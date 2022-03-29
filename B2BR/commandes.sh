Check :

- all group : getent group | awk -F: '{ print $1}' || getent group;

- Sudo group : getent group sudo;

- Local users : cut -d: -f1 /etc/passwd;

- Ssh server : sudo systemctl status ssh || sudo service sshd status;

- Ufw status : sudo ufw status numbered;

- Password : sudo vim/etc/pam.d/common-password;

- VM : lsblk;

- Sudo rules : sudo visudo;

- Ssh connexion : ssh your_username@127.0.0.1 -p 4242

Create :

- Group sudo groupadd name_group;

- User : sudo adduser new_username;

Delete :

- User : sudo deluser "username";

- User from a group : sudo gpasswd --delete username groupname;

- Ufw : sudo ufw delete

- Group : sudo groupdel groupname;

Edit :

- Hostname : hostnamectl set-hostname "new_hostname";
(need to edit file : "vim /etc/hosts");

Assignement :

- Assign user in group, sudo in this case : sudo usermod -aG sudo your_username;

Cron :

- Service cron start;

- Service cron status;

- Service cron stop;

Good To Know:

Difference of CentOS and Debian is it, CentOS is a community supported by the called Red Hat community, they has a large market and its more complicated to upgrade an older version of centOS. Debian in opposite is supported by Debian and is more easy to upgrade.

Difference between aptitude and apt, aptitude is a high level package manager, they have graphic interface and is more intuitive for non-initiate people. apt is more simple and purified,

Difference between SELinux and APPArmor, both are security systems provide tools to isolate application from each other. SELinux is more complicated but you have more control on the process. AppArmor can be handle by human and the system is transparent so it can be indepedently verified.

How work a VM and his purpose? a VM is a simulation create by user to use other OS and to separate some actions from the original computer, it permitted to do some stuff and preserve the original computer.

Choice of operating system : Debian, more simple to use for a non-iniciate.

Difference between apt and aptitude and what is APParmor ? apt (low-level) is based on DLPKG and aptitude (high level) is base on apt. Aptitue had an graphic interface, apt has not.
Apparmor is a security system provide tools to isolate applications from each other.

What is UFW ? Uncomplicated Fire-Wall, it handle the access to the serv or terminal by internet. it open or close some port.

What is LVM ? The LVM purpose is to facilitate managing the storage conflict.

What is SSH ? SSH, Socket SecureShell enable two computer to communicate and share data from distance and with a secure way.

