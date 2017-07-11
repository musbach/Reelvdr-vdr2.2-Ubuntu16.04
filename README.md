# Reelvdr
# vdr 2.2
# Ubuntu 16.04

#installation
apt-get install aptitude
aptitude install git vim vsftpd curl curl-dev libcurl-dev bash-completion auto-completion-el auto-complete-el freetype2 libfreetype6 libfreetype6-dev libfontconfig libfontconfig-dev libtinyxml2.6.2v5 libtinyxml2-dev libtinyxml-dev libtinyxml-dev libmysql++-dev libjpeg-dev libcap-dev libtag1-dev libparted0-dev libavahi-client-dev libxml2-dev libxslt1-dev graphicsmagick-libmagick-dev-compat libcurl3-dev libwebp-dev libdvbcsa-dev libssl-dev libxml2-dev libgstreamer-plugins-base1.0-dev libcddb-dev libboost-dev libgd2-noxpm-dev libept-dev

# eth0
insert into /etc/default/grub:
GRUB_CMDLINE_LINUX_DEFAULT="nomodeset quiet splash video=uvesafb"
GRUB_CMDLINE_LINUX="net.ifnames=0 biosdevname=0 acpi_enforce_resources=lax acpi=ht"

# update modules
insert into /etc/modules
hdshm  //without "has_fb=1"
8021q
