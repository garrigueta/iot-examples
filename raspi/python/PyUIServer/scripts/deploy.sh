sudo apt-get install nginx -y
sudo systemctl start nginx
sudo systemctl enable nginx
cp ./systemd/py-ui-server.service /usr/lib/systemd/system
sudo systemctl start py-ui-server.service
sudo systemctl enable py-ui-server.service
