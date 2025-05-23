static function getServicesByCategory(string $category) {
            $db = getDbConnection();
            $stmt = $db->prepare('
                SELECT service_id, freelancer_id, title, category, image, description, price, min_time, max_time
                FROM services
                WHERE category = ?
            ');
            $stmt->execute(array($category));
            $services = $stmt->fetchAll();
            $rservices = array();
            foreach ($services as $service) {
                array_push($rservices, new Service($service['service_id'], $service['freelancer_id'], $service['title'], $service['category'], $service['image'], $service['description'], $service['price'], $service["min_time"], $service["max_time"]));
            }
            return $rservices;
        }