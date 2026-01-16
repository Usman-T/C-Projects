namespace hellmath
{

  enum class AccountStatus
  {
    troll,
    guest,
    user,
    mod
  };

  enum class Action
  {
    read,
    write,
    remove
  };

  bool display_post(AccountStatus poster_status, AccountStatus viewer_status)
  {
    if (viewer_status == AccountStatus::troll)
    {
      return true;
    }

    return poster_status != AccountStatus::troll;
  }

  // TODO: Task 3 - Implement the `permission_check` function, that takes an
  // `Action` as a first argument and an `AccountStatus` to check against. It
  // should return a `bool`.
  bool permission_check(Action action, AccountStatus status)
  {
    if (status == AccountStatus::mod)
      return true;
    else if (status == AccountStatus::guest && action == Action::read)
      return true;
    else if (action != Action::remove && status != AccountStatus::guest)
      return true;
    else
      return false;
  }

  // TODO: Task 4 - Implement the `valid_player_combination` function that
  // checks if two players can join the same game. The function has two parameters
  // of type `AccountStatus` and returns a `bool`.
  bool valid_player_combination(AccountStatus player1, AccountStatus player2)
  {
    if (player1 == AccountStatus::guest || player2 == AccountStatus::guest)
      return false;

    if (player1 == AccountStatus::troll)
      return !(player2 != AccountStatus::troll);

    if (player2 == AccountStatus::troll)
      return !(player1 != AccountStatus::troll);

    return true;
  }

  // TODO: Task 5 - Implement the `has_priority` function that takes two
  // `AccountStatus` arguments and returns `true`, if and only if the first
  // account has a strictly higher priority than the second.
  bool has_priority(AccountStatus account1, AccountStatus account2)
  {
    return static_cast<int>(account1) > static_cast<int>(account2);
  }

} // namespace hellmath
