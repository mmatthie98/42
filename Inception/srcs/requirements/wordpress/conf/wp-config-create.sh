#!/bin/sh
check_database_connection() {
    mysql -h"$DB_HOST" -u"$MYSQL_USER" -p"$MYSQL_PASSWORD" -e "USE $DB_NAME;" > /dev/null 2>&1
}
if [ ! -f "/var/www/wp-config.php" ]; then
    if check_database_connection; then
        cat << EOF > /var/www/wp-config.php
<?php
define( 'DB_NAME', '$DB_NAME' );
define( 'DB_USER', '$MYSQL_USER' );
define( 'DB_PASSWORD', '$MYSQL_PASSWORD' );
define( 'DB_HOST', 'mariadb' );
define( 'DB_CHARSET', 'utf8' );
define( 'DB_COLLATE', '' );
define('FS_METHOD','direct');
\$table_prefix = 'wp_';
define( 'WP_DEBUG', false );
if ( ! defined( 'ABSPATH' ) ) {
    define( 'ABSPATH', __DIR__ . '/' );
}
require_once ABSPATH . 'wp-settings.php';
EOF
    fi
    if check_database_connection; then
        wp core install --url=$DOMAIN_NAME --title=$WP_TITLE --admin_user=$WP_ADMIN --admin_password=$WP_ADMIN_PASSWORD --admin_email=$WP_ADMIN_EMAIL --skip-email --allow-root
        wp user create $WP_USER $WP_USER_EMAIL --user_pass=$WP_USER_PASSWORD --role=$WP_USER_ROLE --allow-root
    fi
fi
exec php-fpm81 -F
