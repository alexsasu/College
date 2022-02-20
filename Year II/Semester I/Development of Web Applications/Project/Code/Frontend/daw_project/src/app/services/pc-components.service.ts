import { HttpClient, HttpHeaders } from '@angular/common/http';
import { Injectable } from '@angular/core';
import { Observable } from 'rxjs';
import { PcComponent } from '../interfaces/pc-component';

@Injectable({
  providedIn: 'root'
})
export class PcComponentsService {

  public url = 'https://localhost:5001/api/Component';

  public httpOptions = {
    headers: new HttpHeaders()
      .set('Authorization', 'Bearer ' + localStorage.getItem("jwt"))
  };

  constructor(
    public http: HttpClient
  ) { }

  public getComponentById(id: number): Observable<PcComponent> {
    return this.http.get<PcComponent>(`${this.url}/getComponentById/${id}`);
  }

  public getAllComponents(): Observable<PcComponent[]> {
    return this.http.get<PcComponent[]>(`${this.url}/getAllComponentsNotBoughtByClients`);
  }

  public addComponent(component: PcComponent): Observable<PcComponent[]> {
    var componentToReturn = {
      componentId: component.componentId,
      componentName: component.componentName,
      seller: component.seller,
      recommendedForGaming: component.recommendedForGaming,
      price: component.price,
      clientId: 1
    };
    return this.http.post<PcComponent[]>(`${this.url}/${1}`, componentToReturn, this.httpOptions);
  }

  public editComponent(component: PcComponent): Observable<PcComponent[]> {
    var employeeToReturn = [
      {
        value: component.componentName,
        path: "/componentName",
        op: "replace"
      },
      {
        value: component.seller,
        path: "/seller",
        op: "replace"
      },
      {
        value: component.recommendedForGaming,
        path: "/recommendedForGaming",
        op: "replace"
      },
      {
        value: component.price,
        path: "/price",
        op: "replace"
      }
    ]
    return this.http.patch<PcComponent[]>(`${this.url}/${component.componentId}`, employeeToReturn, this.httpOptions);
  }

  public deleteComponent(id: number): Observable<number> {
    const options = {
      headers: this.httpOptions.headers,
      body: id
    };
    return this.http.delete<number>(`${this.url}/${id}`, options);
  }

}