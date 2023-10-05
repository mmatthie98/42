Check :

ufw : sudo allow port_name;

- all group : getent group | awk -F: '{ print $1}' || getent group;

- Sudo group : getent group sudo;

- Local users : cut -d: -f1 /etc/passwd;

- Ssh server : sudo systemctl status ssh || sudo service sshd status;

- Ufw status : sudo ufw status numbered;

- Password : sudo vim/etc/pam.d/common-password;

- VM : lsblk;

- Sudo rules : sudo visudo;

- Ssh connexion : ssh your_username@127.0.0.1 -p 4242;

- password duration : sudo nano /etc/login.defs;

Create :

- Group : sudo groupadd name_group;

- User : sudo adduser new_username;

Delete :

- User : sudo deluser "username";

- User from a group : sudo gpasswd --delete username groupname;

- Ufw : sudo ufw delete

- Group : sudo groupdel groupname;

Edit :

- ufw : sudo ufw allow ssh_port;

- Hostname : hostnamectl set-hostname "new_hostname";
(need to edit file : "vim /etc/hosts");

Assignement :

- Assign user in group, sudo in this case : sudo usermod -aG sudo your_username;

Cron :

- Service cron start;

- Service cron status;

- Service cron stop;

Good To Know:

Une machine virtuelle permet de creer une simulation dun hardware, cela se fait grace a des software et notamment grace a un hyperviseur qui vas permettre de provisionner en memoire, ressource et stockage la machine virtuelle.
cela est possible grace a la virtualisation, la virtualisation utilise un logiciel pour simuler le materiel virtuel qui permet a plusieurs machines de sexecuter sur une seule machine.
le but d'une machine virtuelle est de pouvoir partitionner des taches si on le souhaite, ou bien de pouvoir utiliser un autre systeme d'exploitation.
Une machine virtuelle permet egalement de realiser des actions qui si elles sont grave, n'auront aucun impact sur l'hôte.

Debian et CentOS sont differents sur de nombreux points, cependant les points les plus importants sont ceux-la :

CentOS est supporte par la communaute nommee red hat community, il est difficile d'upgrade une version obsolete de Centos, il est preferable d'en reinstaller une nouvelle version et le market de Centos est bien plus grand.
au contraire Debian est plus facile a upgrade, et est supporte par Debian.

apt et aptitude sont fondamentalement les memes, a quelques differences pres, par exemple aptitude possede une interface graphiphe mais elle s'inspire grandement de apt.
apt quant a lui ne possede pas d'interface graphique mais est plus epure et simple s'inspire de dpkg.

Difference between SELinux and APPArmor, both are security systems provide tools to isolate application from each other. SELinux is more complicated but you have more control on the process. AppArmor can be handle by human and the system is transparent so it can be indepedently verified.

How work a VM and his purpose? a VM is a simulation create by user to use other OS and to separate some actions from the original computer, it permitted to do some stuff and preserve the original computer.

Choice of operating system : Debian, more simple to use for a non-iniciate.

Difference between apt and aptitude and what is APParmor ? apt (low-level) is based on DLPKG and aptitude (high level) is base on apt. Aptitue had an graphic interface, apt has not.
Apparmor is a security system provide tools to isolate applications from each other.

What is UFW ? Uncomplicated Fire-Wall, it handle the access to the serv or terminal by internet. it open or close some port.

What is LVM ? The LVM purpose is to facilitate managing the storage conflict.

What is SSH ? SSH, Socket SecureShell enable two computer to communicate and share data from distance and with a secure way.

