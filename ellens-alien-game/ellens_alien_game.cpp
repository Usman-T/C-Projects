namespace targets
{
  class Alien
  {
  public:
    Alien(int x, int y)
    {
      x_coordinate = x;
      y_coordinate = y;
    }
    int get_health()
    {
      return health;
    }
    bool hit()
    {
      if (health > 0)
        health--;
      return true;
    }
    bool is_alive()
    {
      return health > 0 ? true : false;
    }
    bool teleport(int new_x, int new_y)
    {
      x_coordinate = new_x;
      y_coordinate = new_y;

      return true;
    }
    bool collision_detection(Alien possible_collider)
    {
      if (x_coordinate == possible_collider.x_coordinate &&
          y_coordinate == possible_collider.y_coordinate)
        return true;
      else
        return false;
    }

    int x_coordinate{};
    int y_coordinate{};

  private:
    int health{3};
  };

} // namespace targets
