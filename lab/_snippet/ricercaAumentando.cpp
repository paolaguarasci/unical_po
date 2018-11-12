// Posso aggiungere elementi in una lista
// senza sfanculare il for e l'iteratore
// simula la ricorsione...

int Mobilificio::metodo4()
{
  if (mobili.empty())
    return -1;
  list<string> collaboratori;
  string seed = mobili.back().getProduttore();
  collaboratori.push_back(seed);
  for (list<string>::iterator c_it = collaboratori.begin(); c_it != collaboratori.end(); c_it++)
  {
    string key = (*c_it);
    for (list<Mobile>::iterator it = mobili.begin(); it != mobili.end(); it++)
    {
      if (it->getProduttore() == key && it->getCollaboratore() != "")
      {
        collaboratori.push_back(it->getCollaboratore());
      }
    }
  }
  collaboratori.sort();
  collaboratori.unique();
  return collaboratori.size();
}