#!/bin/bash

/bin/bash -C /set_autoindex.sh

service nginx start
service mysql start
service php7.3-fpm start
bash
