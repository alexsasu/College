import { HttpClient, HttpHeaders } from '@angular/common/http';
import { Injectable } from '@angular/core';
import { Observable } from 'rxjs';
import { Client } from '../interfaces/client';

@Injectable({
  providedIn: 'root'
})
export class ClientsService {

  public url = 'https://localhost:5001/api/Client';

  public httpOptions = {
    headers: new HttpHeaders()
      .set('Authorization', 'Bearer ' + localStorage.getItem("jwt"))
  };

  constructor(
    public http: HttpClient
  ) { }

  public getClientById(id: number): Observable<Client> {
    return this.http.get<Client>(`${this.url}/${id}`, this.httpOptions);
  }

  public getAllClientsWithTheirDeliveryAddress(): Observable<Client[]> {
    return this.http.get<Client[]>(`${this.url}/getAllClientsWithTheirDeliveryAddress`, this.httpOptions);
  }

  public addClient(client: Client): Observable<Client[]> {
    var clientToReturn = {
      clientId: client.clientId,
      clientLastName: client.clientLastName,
      clientFirstName: client.clientFirstName,
      deliveryAddressId: client.deliveryAddressId,
      deliveryAddress: {
        country: client.country,
        city: client.city,
        street: client.street,
        streetNumber: client.streetNumber
      }
    };
    return this.http.post<Client[]>(`${this.url}`, clientToReturn, this.httpOptions);
  }

  public editClient(client: Client): Observable<Client[]> {
    var clientToReturn = [
      {
        value: client.clientLastName,
        path: "/clientLastName",
        op: "replace"
      },
      {
        value: client.clientFirstName,
        path: "/clientFirstName",
        op: "replace"
      },
      {
        value : {
          deliveryAddressId: client.deliveryAddressId,
          country: client.country,
          city: client.city,
          street: client.street,
          streetNumber: client.streetNumber
        },
        path: "/deliveryAddress",
        op: "replace"
      }
    ]
    return this.http.patch<Client[]>(`${this.url}/${client.clientId}`, clientToReturn, this.httpOptions);
  }

  public deleteClient(id: number): Observable<number> {
    const options = {
      headers: this.httpOptions.headers,
      body: id
    };
    return this.http.delete<number>(`${this.url}/${id}`, options);
  }

}