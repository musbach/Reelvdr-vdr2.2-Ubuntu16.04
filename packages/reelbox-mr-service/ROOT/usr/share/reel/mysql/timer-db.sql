USE vdr;
CREATE TABLE timer (id INT NOT NULL AUTO_INCREMENT, flags TINYINT UNSIGNED, channel VARCHAR(128), date VARCHAR(64), start VARCHAR(4), stop VARCHAR(4), priority TINYINT, lifetime TINYINT, file VARCHAR(256), aux VARCHAR(512), ip VARCHAR(16), PRIMARY KEY(id));
CREATE TRIGGER insert_timer AFTER INSERT ON timer FOR EACH ROW INSERT INTO vdr_event (object_id, table_name, action) VALUES (NEW.id, 'timer', 'insert');
CREATE TRIGGER update_timer AFTER UPDATE ON timer FOR EACH ROW INSERT INTO vdr_event (object_id, table_name, action) VALUES (OLD.id, 'timer', 'update');
CREATE TRIGGER delete_timer AFTER DELETE ON timer FOR EACH ROW INSERT INTO vdr_event (object_id, table_name, action) VALUES (OLD.id, 'timer', 'delete');
GRANT SELECT,INSERT,UPDATE,DELETE on vdr.timer to 'reeluser'@'%' IDENTIFIED BY 'reeluser';
GRANT SELECT,INSERT,UPDATE,DELETE on vdr.timer to 'reeluser'@'localhost' IDENTIFIED BY 'reeluser';
